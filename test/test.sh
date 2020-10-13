#!/bin/sh

#
# This file is licensed under BSD 3-Clause.
# All license information is available in the included COPYING file.
#

#
# test.sh
# This file will check the output of test files against known
# correct opcode sequences. Do not call this file directly,
# instead go to the root directory and call `make test`.
#
# Author       : Finn Rayment <finn@rayment.fr>
# Date created : 13/10/2020
#

CC=gcc

for i in */*.c;
do
	$CC $i -I../include -L../lib -lblink
	x="$(dirname $i)/$(basename -s .c $i)"
	(./a.out | (diff $x.bin /dev/fd/3) 3<&0) >/dev/null
	if [ $? -ne 0 ];
	then
		echo "[n] Test failed: $x"
		echo "===== EXPECTED ====="
		xxd $x.bin
		echo "===== RECEIVED ====="
		(./a.out | (xxd /dev/fd/3) 3<&0)
	else
		echo "[y] Test passed: $x"
	fi
done

rm -f a.out

