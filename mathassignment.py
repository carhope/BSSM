# permutation_combination_recursion_template.py
# [수학 & 프로그래밍 융합 수행평가]
# 점화식을 활용한 경우의 수 구현 및 탐구
#
# 주의:
# - itertools 사용 금지
# - 순열/조합을 바로 만들어 주는 외부 라이브러리 사용 금지
# - 아래 함수 이름과 매개변수는 바꾸지 마세요.


def get_permutations(arr, r):
    """주어진 리스트 arr에서 r개를 뽑아 나열하는 모든 순열을 반환하는 재귀함수"""
    if r == 0:
        return [[]]

    result = []
    for i in range(len(arr)):
        selected = arr[i] #하나 선택
        rest = arr[:i] + arr[i + 1:] #선택한거 제외 앞뒤 가져옴

        # TODO: rest에서 r-1개를 뽑는 순열을 구하고 selected와 연결하기
        for j in get_permutations(rest, r-1):
            result.append([selected] + j)

            

    return result


def get_combinations(arr, r):
    """주어진 리스트 arr에서 r개를 뽑는 모든 조합을 반환하는 재귀함수 (원소 순서 유지)"""
    if r == 0:
        return [[]]

    if len(arr) < r:
        return []

    first = arr[0]
    rest = arr[1:]

    # TODO: first를 포함하는 조합: rest에서 r-1개를 뽑은 결과 앞에 first 붙이기
    include_first = []

    for i in get_combinations(rest, r-1):
        include_first.append([first] + i)

    # TODO: first를 포함하지 않는 조합: rest에서 r개를 뽑기
    exclude_first = []
    for k in get_combinations(rest, r):
        exclude_first.append(k)

    return include_first + exclude_first


def solve_problem_a():
    """문제 A 검증용 함수: 조건에 맞는 순열 개수를 직접 세어 보세요."""
    letters = ['a', 'e', 'b', 'c', 'd']
    cases = get_permutations(letters, 5)
    print(cases)
    adjacent_count = 0
    for case in cases:
        # TODO: a와 e의 위치 차이가 1인지 확인하세요.
        for k in range(len(case)-1):
            if case[k] + case[k+1] in ['ea','ae']:
                adjacent_count +=1
                print(case[k] + case[k+1])


    alternating_count = 0
    vowels = ['a', 'e']
    consonants = ['b', 'c', 'd']
    for case in cases:
        # TODO: 각 위치의 모음/자음 패턴이 교대로 나타나는지 확인하세요.
        if case in vowels and next in consonants:
            alternating_count +=1

    print('문제 A (1):', adjacent_count)
    print('문제 A (2):', alternating_count)


def solve_problem_b():
    """문제 B 검증용 함수: 조건에 맞는 조합 개수를 직접 세어 보세요."""
    cards = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    cases = get_combinations(cards, 3)

    include_7_count = 0
    for case in cases:
        # TODO: 7이 case 안에 있는지 확인하세요.
        pass

    even2_odd1_count = 0
    for case in cases:
        # TODO: 짝수 개수와 홀수 개수를 세어 조건을 확인하세요.
        pass

    print('문제 B (1):', include_7_count)
    print('문제 B (2):', even2_odd1_count)


if __name__ == '__main__':
    # 함수가 완성되면 아래 주석을 해제해서 실행하세요.
    print(get_permutations(['A', 'B', 'C'], 2))
    print(get_combinations(['A', 'B', 'C'], 2))
    solve_problem_a()
    # solve_problem_b()
    pass