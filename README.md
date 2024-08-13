# ABOUT
Hi. That is a library to work with rational numbers.

# BUILD
This project uses cmake. in the root dir run the following command:
```bash
cmake . -DBUILD_SHARED_LIBRARIES=ON -B build -S . -G "your generator"; if($?) {cmake --build .\build} 
```
to customize library type change *-DBUILD_SHARED_LIBRARIES* flag in the command above.
