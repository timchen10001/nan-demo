{
  "targets": [
    {
      "target_name": "object",
      "sources": [ "obj-factory.cpp" ],
      "include_dirs": [
          "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}