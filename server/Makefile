serverBin = ./cmds/server/bin/server
serverPackage = ./cmds/server
serverRecourceRoot = ./resource

.PHONY: buildAndRun
buildAndRun:
	go build -o $(serverBin) $(serverPackage)
	$(serverBin) -port $(SERVER_PORT) -resourceRoot $(serverRecourceRoot)