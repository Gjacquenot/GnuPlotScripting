#include "GnuPlotScripting/global_config.hpp"

#include <cassert>
#include <iostream>

namespace GnuPlotScripting
{
  struct Global_Config::Interface
  {
    bool _log                               = true;
    Script_File_Mode_Enum _script_file_mode = Script_File_Mode_Enum::None;
  };

  Global_Config::Global_Config() : _pimpl(std::make_unique<Interface>()) {}
  Global_Config::~Global_Config() {}

  Global_Config&
  Global_Config::set_log(bool on_off)
  {
    _pimpl->_log = on_off;
    return *this;
  }
  bool
  Global_Config::log() const
  {
    return _pimpl->_log;
  }
  Global_Config&
  Global_Config::set_log_message(const char* const msg) 
  {
    assert(log());

    std::cerr << "[GnuPlotScripting] : " << msg << std::endl;

    return *this;
  }

  Global_Config&
  Global_Config::set_file_script_mode(Script_File_Mode_Enum mode)
  {
    _pimpl->_script_file_mode = mode;
    return *this;
  }

  Script_File_Mode_Enum
  Global_Config::file_script_mode() const
  {
    return _pimpl->_script_file_mode;
  }

  ////////////////////////////////////////////////////////////////

  Global_Config&
  global_config()
  {
    static Global_Config config;
    return config;
  }
}
