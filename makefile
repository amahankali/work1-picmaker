compile:
	gcc draw.c

run: compile
	./a.out
	convert arrow.ppm firstPic.png
	rm arrow.ppm

clean:
	rm firstPic.png
	rm a.out
