file(REMOVE_RECURSE
  "../../gen/include/dawn/dawn_proc_table.h"
  "../../gen/include/dawn/webgpu.h"
  "../../gen/include/dawn/wire/client/webgpu.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/dawn_headers.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
