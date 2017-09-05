#!/bin/bash

if [ $# -ne 2 ]
then
	echo "Usage: $0 <IP> <PORT>"
	exit 1
fi

echo "Basic tests"
./mouli_connect				$1 $2
./mouli_multipleconnect			$1 $2

echo "Advanced Tests"
./mouli_channel_join			$1 $2
./mouli_channel_multiplejoin		$1 $2
./mouli_channel_join_propagation	$1 $2

./mouli_channel_leave			$1 $2
./mouli_channel_leave_propagation	$1 $2

./mouli_message_private			$1 $2
./mouli_message_propagation		$1 $2

./mouli_nickname			$1 $2
./mouli_nickname_propagation		$1 $2
