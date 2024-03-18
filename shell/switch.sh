#!/bin/bash
echo choose an option
echo a=hello
echo world

read choice

case $choice in
	a)date;;
	b)ls;;
	*)echo "hello"
esac