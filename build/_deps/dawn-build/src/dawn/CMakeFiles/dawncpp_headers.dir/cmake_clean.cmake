file(REMOVE_RECURSE
  "../../gen/include/dawn/webgpu_cpp.h"
  "../../gen/include/dawn/webgpu_cpp_print.h"
  "../../gen/include/dawn/wire/client/webgpu_cpp.h"
  "../../gen/include/webgpu/webgpu_cpp_chained_struct.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/dawncpp_headers.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
