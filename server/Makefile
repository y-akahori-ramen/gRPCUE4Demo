serverBin = ./cmds/server/bin/server
serverPackage = ./cmds/server

.PHONY: buildAndRun
buildAndRun:
	go build -o $(serverBin) $(serverPackage)
	$(serverBin) -port $(SERVER_PORT)