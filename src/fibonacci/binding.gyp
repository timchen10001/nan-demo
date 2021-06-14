{ "targets": [ { "target_name": "fibonacci", "sources": [ "fibonacci.cpp" ], "include_dirs": [ "<!(node -e \"require('nan')\")" ] } ] }
