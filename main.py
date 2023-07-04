print('Welcome to am I a Mechanic test')
answer = input('Are you ready to play the Quiz ?')
score = 0
total_questions = 3

if answer.lower() == 'yes':
    answer = input('Question 1: What is an intake manifold? a) Part of the Induction System b) Part of the Cooling '
                   'System c) Part of the Brake System')
    if answer.lower() == 'a':
        score += 1
        print('Correct')
    else:
        print('Wrong Answer')

    answer = input('Question 2: What is DOHC stand for? a) Dual Overhead Cam b) Dual Orifice Heat Collector c) Dual '
                   'Oxygen Hydrogen Collector ')
    if answer.lower() == 'a':
        score += 1
        print('Correct')
    else:
        print('Wrong Answer')

    answer = input('Question 3: What is part of the ignition system a) BCM b) Coil Spring c) Spark Plug ')
    if answer.lower() == 'c':
        score += 1
        print('Correct')
    else:
        print('Wrong Answer')

print('Thank you for playing this quiz,', score, "questions correctly!")
mark: float = (score / total_questions) * 100
print('Marks obtained:', mark)
print('Bye! ')
