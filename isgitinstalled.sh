#!/usr/bin/env bash

GIT_VERSION="$(git --version)"
if [ "$GIT_VERSION" != "command not found" ]; then
  echo "git already" installed
else
    echo "git is missing"
fi

