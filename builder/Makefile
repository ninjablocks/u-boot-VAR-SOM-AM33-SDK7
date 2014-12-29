all: ../tools/mkenvimage ../tools/crc32sum

docker-image:
	docker build -t u-boot-builder .

docker-shell: docker-image
	docker run --rm -it u-boot-builder bash

../tools/mkenvimage: docker-image
	CTR=$$(docker run -d u-boot-builder sh -c 'git pull --rebase origin && make tools') && \
	docker wait $$CTR && \
	docker cp $$CTR:/data/git/u-boot-VAR-SOM-AM33-SDK7/tools/mkenvimage ../tools && \
	docker rm $$CTR

../tools/crc32sum: docker-image
	CTR=$$(docker run -d u-boot-builder sh -c 'git pull --rebase origin && make tools') && \
	docker wait $$CTR && \
	docker cp $$CTR:/data/git/u-boot-VAR-SOM-AM33-SDK7/tools/crc32sum ../tools && \
	docker rm $$CTR