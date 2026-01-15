# run time and save output in owi-time.txt
# also save ALL owi std out/err to owi-output.txt
/usr/bin/time -v -o owi-time.txt \
	owi sym main.wasm --deterministic-result-order -d &> owi-output.txt