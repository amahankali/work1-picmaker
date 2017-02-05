compile:
	gcc draw.c

run: compile
	./a.out
	convert arrow.ppm firstPic.png

clean:
	rm arrow.ppm
	rm firstPic.png
	rm a.out
