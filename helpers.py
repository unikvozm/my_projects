from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    lines_a = a.split("\n")
    lines_b = b.split("\n")

    result_lines = []
    for i in lines_a:
        for j in lines_b:
            if i == j and j not in result_lines:
                result_lines.append(j)

    return result_lines


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    sentences_a = sent_tokenize(a)
    sentences_b = sent_tokenize(b)

    result_sentences = []
    for i in sentences_a:
        for j in sentences_b:
            if i == j and j not in result_sentences:
                result_sentences.append(j)

    return result_sentences


def substrings_splitting(s, n):
    substrings = []
    for i in range(len(s) - n + 1):
        substrings.append(s[i:i + n])

    return substrings


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    substrings_a = substrings_splitting(a, n)
    substrings_b = substrings_splitting(b, n)

    result_substrings = []
    for i in substrings_a:
        for j in substrings_b:
            if i == j and j not in result_substrings:
                result_substrings.append(j)

    return result_substrings