for i in {1..20}
do
    args=$(python3 -c "import random, sys; n = int(sys.argv[1]); print(' '.join(map(str, random.sample(range(-n, n), n))))" "$1")

    instruction_count=$(./push_swap $args | wc -l)

    test_ok=$(./push_swap $args | ./checker_linux $args)

    echo "Number of instructions: $instruction_count"
    echo "Is sorted?: $test_ok"
done
