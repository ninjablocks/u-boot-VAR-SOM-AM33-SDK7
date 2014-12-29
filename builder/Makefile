docker-image:
		docker build -t u-boot-builder .

docker-shell: docker-image
		docker run --rm -it u-boot-builder bash
