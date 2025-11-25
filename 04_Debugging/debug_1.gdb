set pagination off

file ./range

break 25 if (i % 5 == 0)
    command 1
    printf "@@@ n=%d m=%d s=%d i=%d\n", n, m, s, i
    continue
end

run 1 12 > /dev/null
quit
