licenses(["notice"])

exports_files([
    "LICENSE",
    "NOTICE",
])

COPTS = [
    "-UNDEBUG",
    "-Wno-unused-parameter",
]

LIBS = [
    "@libcolhash//:colhash",
    "@libprim//:prim",
    "@libfactory//:factory",
    "@librnd//:rnd",
    "@libmut//:mut",
    "@libbits//:bits",
    "@libstrop//:strop",
    "@libfio//:fio",
    "@libsettings//:settings",
    "@zlib//:zlib",
    "@jsoncpp//:jsoncpp",
]

cc_library(
    name = "lib",
    srcs = glob(
        ["src/**/*.cc"],
        exclude = [
            "src/**/*_TEST*",
        ],
    ),
    hdrs = glob(
        [
            "src/**/*.h",
            "src/**/*.tcc",
        ],
        exclude = ["src/**/*_TEST*"],
    ),
    copts = COPTS,
    includes = [
        "src",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "@supersim//:lib",
    ] + LIBS,
    alwayslink = 1,
)

cc_binary(
    name = "supersim",
    copts = COPTS,
    includes = [
        "src",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":lib",
        "@supersim//:main",
    ] + LIBS,
)

[
    cc_test(
        name = test_file.replace(".cc", ""),
        srcs = [test_file],
        args = [
            "--gtest_color=yes",
        ],
        copts = COPTS,
        visibility = ["//visibility:public"],
        deps = [
            ":lib",
            "@supersim//:test_lib",
        ] + LIBS,
    )
    for test_file in glob(["src/**/*_TEST.cc"])
]

test_suite(
    name = "unit_tests",
    tests = [test_file.replace(".cc", "")
             for test_file in glob(["src/**/*_TEST.cc"])],
)

genrule(
    name = "lint",
    srcs = glob([
        "src/**/*.cc",
    ]) + glob([
        "src/**/*.h",
        "src/**/*.tcc",
    ]),
    outs = ["linted"],
    cmd = """
    python $(location @cpplint//:cpplint) \
      --root=$$(pwd)/src \
      --headers=h,tcc \
      --extensions=cc,h,tcc \
      --quiet $(SRCS) > $@
    echo // $$(date) > $@
  """,
    tools = [
        "@cpplint",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "config_files",
    srcs = glob(["config/*"]),
)

[
    sh_test(
        name = config_file + "_check",
        srcs = ["scripts/run_example.sh"],
        args = [
            config_file,
        ],
        data = [
            ":config_files",
            ":supersim",
            "@supersim//:run_example",
        ],
    )
    for config_file in glob(["config/*.json"])
]

test_suite(
    name = "config_tests",
    tests = [config_file + "_check" for config_file in glob(["config/*.json"])],
)
