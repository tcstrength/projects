libtest02_sources = [
    'student.hpp',
    'student.cpp'
]

libtest02 = static_library(
    'test02',
    libtest02_sources,
)

libtest02_dep = declare_dependency(
    link_with: libtest02
)

test02 = executable(
	'test02', 
	'main.cpp',
	dependencies: libtest02_dep,
	install: true
)