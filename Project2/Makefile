all:
	cp -r /home/cs/232/projects/2/2019/ .
	chmod +x clean
	
	################SCRIPT 2.########################
	./clean 2019/partA
	################SCRIPT 3.########################
	du -sh * | grep 2019
	rm -r 2019/
	
	################SCRIPT 4.########################
	cp -r /home/cs/232/projects/2/2019/ .
	chmod +x clean
	./clean
	################SCRIPT 5.########################
	du -sh * | grep 2019
	rm -r 2019/

	################EXTRA CREDIT Q.########################
	cp -r /home/cs/232/projects/2/2019/ .
	chmod +x clean
	./clean 2019 -q
	du -sh * | grep 2019
	rm -r 2019/

	################EXTRA CREDIT S.########################
	cp -r /home/cs/232/projects/2/2019/ .
	chmod +x clean
	./clean 2019 -s
	du -sh * | grep 2019
	rm -r 2019/

	################EXTRA CREDIT I.########################
	cp -r /home/cs/232/projects/2/2019/ .
	chmod +x clean
	./clean 2019/partA -i -s
	du -sh * | grep 2019
	rm -r 2019/

	cp -r /home/cs/232/projects/2/2019/ .
clean:
	rm -r 2019/