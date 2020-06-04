{
    "targets": [{
        "target_name": "converter",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/ANPR_archivio_comuni_semplice.csv",
            "src/aiken.cpp",
            "src/code.cpp",
            "src/gray.cpp",
            "src/quinary.cpp",
            "src/utf8.cpp",
            "src/aiken.hpp",
            "src/code.hpp",
            "src/gray.hpp",
            "src/quinary.hpp",
            "src/utf8.hpp",
            "src/ascii.cpp",
            "src/conversion.cpp",
            "src/interface.cpp",
            "src/roman.cpp",
            "src/weighted.cpp",
            "src/ascii.hpp",
            "src/conversion.hpp",
            "src/main.cpp",
            "src/roman.hpp",
            "src/weighted.hpp",
            "src/bcd.cpp",
            "src/fiscal.cpp",
            "src/numeric.cpp",
            "src/segment7.cpp",
            "src/xs3.cpp",
            "src/bcd.hpp",
            "src/fiscal.hpp",
            "src/numeric.hpp",
            "src/segment7.hpp",
            "src/xs3.hpp",
            "src/biquinary.cpp",
            "src/fiscale.cpp",
            "src/oneOfN.cpp",
            "src/twoOnFive.cpp",
            "src/xs3r.cpp",
            "src/biquinary.hpp",
            "src/fiscale.hpp",
            "src/oneOfN.hpp",
            "src/twoOnFive.hpp",
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
