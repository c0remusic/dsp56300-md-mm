set(ASMJIT_STATIC TRUE)

option(DSP56K_FORCE_INTERPRETER "Disable the JIT and use the interpreter" OFF)

add_subdirectory(asmjit)
add_subdirectory(dsp56kBase)
add_subdirectory(dsp56kEmu)
add_subdirectory(dsp56kTestRunner)
add_subdirectory(disassemble)

set_property(TARGET asmjit PROPERTY FOLDER "dsp56300")
set_property(TARGET dsp56kBase PROPERTY FOLDER "dsp56300")
set_property(TARGET dsp56kEmu PROPERTY FOLDER "dsp56300")
set_property(TARGET dsp56kTestRunner PROPERTY FOLDER "dsp56300")
set_property(TARGET dsp56kDisassemble PROPERTY FOLDER "dsp56300")

if(WIN32 OR (UNIX AND NOT APPLE))
	add_subdirectory(vtuneSdk)
	set_property(TARGET vtuneSdk PROPERTY FOLDER "dsp56300")
endif()
