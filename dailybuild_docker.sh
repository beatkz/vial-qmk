#!/bin/bash
pushd "$(dirname "${BASH_SOURCE[0]}")" > /dev/null
docker compose run --user $(id -u):$(id -g) --rm build 
sleep 5
popd > /dev/null
