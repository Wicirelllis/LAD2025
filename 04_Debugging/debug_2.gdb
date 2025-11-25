set pagination off

file ./range

set $counter=0

break 25 if (28 <= $counter++ && $counter <= 35)
    command 1
    printf "@@@ n=%d m=%d s=%d i=%d\n", n, m, s, i
    continue
end

run -100 100 3 > /dev/null
quit
