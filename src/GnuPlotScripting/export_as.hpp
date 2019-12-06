#pragma once

#include <filesystem>
#include <memory>
#include <string>

namespace GnuPlotScripting
{
  ///////////////
  // Export_As //
  ///////////////
  //
  class Export_As
  {
   public:
    struct Interface
    {
      virtual std::string export_as(const std::filesystem::path& filename) const = 0;

      virtual ~Interface() = default;
    };

   protected:
    using pimpl_type = std::unique_ptr<Interface>;
    pimpl_type _pimpl;

    Export_As(pimpl_type&& pimpl);

   public:
    std::string export_as(const std::filesystem::path& filename) const;
  };

  /////////
  // PNG //
  /////////
  //
  class PNG : public Export_As
  {
    struct PNG_Interface;
    PNG_Interface& impl();

   public:
    PNG();

    PNG& set_free_form(const std::string& free_form = "");

    PNG& set_enhanced(bool yes_no);
    PNG& set_enhanced();  // back to default

    PNG& set_transparent(bool yes_no);
    PNG& set_transparent();  // back to default

    PNG& set_interlace(bool yes_no);
    PNG& set_interlace();  // back to default
  };

  //////////////
  // EPSLATEX //
  //////////////
  //
  class EPSLATEX : public Export_As
  {
    struct EPSLATEX_Interface;
    EPSLATEX_Interface& impl();

   public:
    EPSLATEX();

    EPSLATEX& set_free_form(const std::string& free_form = "");

    EPSLATEX& set_standalone(bool yes_no);
    EPSLATEX& set_standalone();  // back to default

    EPSLATEX& set_color(bool yes_no);
    EPSLATEX& set_color();  // back to default

    EPSLATEX& set_clip(bool yes_no);
    EPSLATEX& set_clip();  // back to default

    EPSLATEX& set_header(const std::string& header = "");
  };

}
