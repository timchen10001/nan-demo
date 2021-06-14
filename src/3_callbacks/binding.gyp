{
    "targets": [
        {
            "target_name": "callback",
            "sources": ["callback.cpp"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
