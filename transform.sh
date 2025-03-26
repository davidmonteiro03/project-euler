#!/bin/bash

enable_e=false
args=()
disable_options=false

for arg in "$@"
do
	if $disable_options
	then
		args+=("$arg")
	elif [[ "$arg" == "-" ]]
	then
		disable_options=true
	elif [[ "$arg" == -* ]]
	then
		for (( i=1; i<${#arg}; i++ ))
		do
			if [[ "${arg:i:1}" == "e" ]]
			then
				enable_e=true
			else
				echo "Error: Unsupported option '${arg:i:1}'"
				exit 1
			fi
		done
	else
		args+=("$arg")
	fi
done

input=""
for (( i=0; i<${#args[@]}; i++ ))
do
	if (( i > 0 ))
	then
		input+=" "
	fi
	input+="${args[i]}"
done

result=$(echo $(echo $input |
	iconv -f UTF-8 -t ASCII//TRANSLIT |
	sed 's/[^a-zA-Z0-9]/\n/g' |
	grep -v '^$' |
	tr '\n' ' ') |
	sed 's/[^a-zA-Z0-9]/_/g' |
	tr '[:upper:]' '[:lower:]')

if eval $enable_e
then
	result=$(echo $result |
		tr 'abcdefghijklmnopqrstuvwxyz' 'nopqrstuvwxyzabcdefghijklm' |
		tr '0123456789' '5678901234' |
		tr 'abcdefghijklmnopqrstuvwxyz0123456789' 'stuvwxyz0123456789abcdefghijklmnopqr' |
		tr -d '_')
fi

echo "Result: $result"
