#!/bin/bash
pushd "$(dirname "${BASH_SOURCE[0]}")" > /dev/null
docker compose run --rm build
sleep 10
popd > /dev/null
