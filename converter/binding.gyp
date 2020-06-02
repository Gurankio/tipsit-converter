{
    "targets": [{
        "target_name": "converter",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/aiken.cpp",
            "src/aiken.hpp",
            "src/ascii.cpp",
            "src/ascii.hpp",
            "src/bcd.cpp",
            "src/bcd.hpp",
            "src/biquinary.cpp",
            "src/biquinary.hpp",
            "src/code.cpp",
            "src/code.hpp",
            "src/conversion.cpp",
            "src/conversion.hpp",
            "src/interface.cpp",
            "src/numeric.cpp",
            "src/numeric.hpp",
            "src/quinary.cpp",
            "src/quinary.hpp",
            "src/twoOnFive.cpp",
            "src/twoOnFive.hpp",
            "src/weighted.cpp",
            "src/weighted.hpp",
            "src/xs3.cpp",
            "src/xs3.hpp",
            "src/xs3r.cpp",
            "src/xs3r.hpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
