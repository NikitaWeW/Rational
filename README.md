hi. that is a library to work with rational numbers. thats it.

###BUILD###
this project uses cmake. in the root dir run the following command:
	cmake . -DBUILD_SHARED_LIBRARIES=ON -B build -S . -G "MinGW Makefiles"; if($?) {cmake --build .\build} 
to customize library type change -DBUILD_SHARED_LIBRARIES flag in the command above.