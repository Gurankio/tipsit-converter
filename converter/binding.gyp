{
    "targets": [{
        "target_name": "converter",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "aiken.cpp",
            "code.cpp",
            "gray.cpp",
            "quinary.cpp",
            "utf8.cpp",
            "aiken.hpp",
            "code.hpp",
            "gray.hpp",
            "quinary.hpp",
            "utf8.hpp",
            "ascii.cpp",
            "conversion.cpp",
            "interface.cpp",
            "roman.cpp",
            "weighted.cpp",
            "ascii.hpp",
            "conversion.hpp",
            "main.cpp",
            "roman.hpp",
            "weighted.hpp",
            "bcd.cpp",
            "fiscal.cpp",
            "numeric.cpp",
            "segment7.cpp",
            "xs3.cpp",
            "bcd.hpp",
            "fiscal.hpp",
            "numeric.hpp",
            "segment7.hpp",
            "xs3.hpp",
            "biquinary.cpp",
            "fiscale.cpp",
            "oneOfN.cpp",
            "twoOnFive.cpp",
            "xs3r.cpp",
            "biquinary.hpp",
            "fiscale.hpp",
            "oneOfN.hpp",
            "twoOnFive.hpp",
            "xs3r.hpp"
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
