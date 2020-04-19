.PHONY: test

test:
	gcc -o temp_build -pthread test.c
	./temp_build

clean:
	rm temp_build 
