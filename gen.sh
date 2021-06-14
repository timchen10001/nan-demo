#!/bin/bash

echo ">>> File Name"

read FILE_NAME

echo ">>> Module Name"

read MODULE_NAME

cd "src"

mkdir $MODULE_NAME && cd $MODULE_NAME

touch "$MODULE_NAME.$FILE_NAME" && touch "$MODULE_NAME.js"

binding='{
  "targets": [
    {
      "target_name": "1",
      "sources": [ "1.2" ],
      "include_dirs": [
          "<!(node -e \"require(\''nan\'')\")"
      ]
    }
  ]
}'

binding=${binding/1/$MODULE_NAME}
binding=${binding/1/$MODULE_NAME}
binding=${binding/2/$FILE_NAME}

echo $binding >> binding.gyp

npm init -y && yarn install
