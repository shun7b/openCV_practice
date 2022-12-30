all:./cam
	./cam
./cam:camera_test2.cpp 
	g++  camera_test2.cpp -o $@  -I/usr/local/include/opencv4  -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -o cam| sudo chmod g+rw /dev/video*
#FromPhoto.o:FromPhoto.cpp
#	g++ -c $<  -I/usr/local/include/opencv4  -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -o cam| sudo chmod g+rw /dev/video*
clean:
	rm ./cam  block.csv| cp org.csv sig.csv| sudo chgrp video /dev/video* 
