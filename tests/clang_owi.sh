clang -O3 --target=wasm32 -m32 -ffreestanding \
	--no-standard-libraries -Wno-everything -flto=thin \
	-Wl,--entry=main -Wl,--export=main -Wl,--lto-O0 -Wl,-z,stack-size=8388608 \
	-I /home/cacete/.opam/default/share/owi/libc -o main.wasm \
	/home/cacete/.opam/default/share/owi/binc/libc.wasm \
	main.c