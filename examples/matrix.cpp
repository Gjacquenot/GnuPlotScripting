
#include "GnuPlotScripting/GnuPlotScripting.hpp"

#include <iostream>

using namespace GnuPlotScripting;

// Example from: https://stackoverflow.com/questions/27045964/multiple-palettes-and-empty-labels-from-file-entries-using-matrix-with-image-in/27049991#27049991
// Another matrix example: https://stackoverflow.com/questions/32458753/gnuplot-2d-plot-of-a-matrix-of-data
int
main()
{
  //  global_config().set_log(true);

  Data_Ascii data(
      "0.00 0.65 0.65 0.25\n"
      "0.25 0.00 0.75 0.25\n"
      "0.50 0.60 0.00 0.25\n"
      "0.75 0.25 0.10 0.00\n");

  Script_File script("matrix.gp");

  script.free_form("set autoscale fix");
  script.free_form("set cbrange [-1:1]");
  script.free_form("unset colorbox");
  script.free_form("unset key");
  script.free_form(
      "plot {} matrix using 1:2:3 with image, '' matrix using "
      "1:2:(sprintf('%.2f', $3)) with labels font ',16'",
      data);
  script.export_as(PNG(),"./test");
}
