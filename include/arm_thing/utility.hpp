#ifndef ARM_THING_UTILITY_HPP
#define ARM_THING_UTILITY_HPP

#include <vector>
#include <cstdint>
#include <filesystem>

namespace spdlog {
struct logger;
}

namespace arm_thing {
namespace elf {
  struct File_Header;
}

std::vector<uint8_t> read_file(const std::filesystem::path &t_path);


void resolve_symbols(std::vector<std::uint8_t> &data, const arm_thing::elf::File_Header &file_header, spdlog::logger &logger);

// creates an RAII managed temporary directory
struct Temp_Directory
{
  Temp_Directory(const std::string_view t_prefix);
  ~Temp_Directory();

  const std::filesystem::path &dir() { return m_dir; }

  Temp_Directory(Temp_Directory &&)      = delete;
  Temp_Directory(const Temp_Directory &) = delete;
  Temp_Directory &operator=(const Temp_Directory &) = delete;
  Temp_Directory &operator=(Temp_Directory &&) = delete;

private:
  std::filesystem::path m_dir;
};
}  // namespace arm_thing


#endif
