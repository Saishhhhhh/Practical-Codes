import math

# ---------- Alpha-Beta Search for Guessing ----------
def alpha_beta_guess(low, high, secret, is_maximizing, alpha, beta, depth=0):
    # If the range has collapsed to one number
    if low == high:
        # If it's the correct number, AI wins
        if low == secret:
            return 10 - depth  # Higher score for faster guesses
        else:
            return depth - 10  # Wrong number
    
    if is_maximizing:  # AI's turn (trying to guess)
        best = -math.inf
        for guess in range(low, high + 1):
            # Simulate human feedback
            if guess == secret:
                score = 10 - depth
            elif guess < secret:
                score = alpha_beta_guess(guess + 1, high, secret, False, alpha, beta, depth + 1)
            else:
                score = alpha_beta_guess(low, guess - 1, secret, False, alpha, beta, depth + 1)
            
            best = max(best, score)
            alpha = max(alpha, best)
            if beta <= alpha:
                break  # prune
        return best
    else:  # Human feedback side (minimizing)
        best = math.inf
        for guess in range(low, high + 1):
            # Human "feedback" simulation
            if guess == secret:
                score = 10 - depth
            elif guess < secret:
                score = alpha_beta_guess(guess + 1, high, secret, True, alpha, beta, depth + 1)
            else:
                score = alpha_beta_guess(low, guess - 1, secret, True, alpha, beta, depth + 1)
            
            best = min(best, score)
            beta = min(beta, best)
            if beta <= alpha:
                break  # prune
        return best

# ---------- AI Play Function ----------
def ai_guess(low, high):
    # Binary Search Logic (optimized guess)
    return (low + high) // 2

# ---------- Game Loop ----------
print("🎯 Guess the Number Game (AI Version)")
print("Think of a number between 1 and 100. I’ll guess it!")

low, high = 1, 100
guesses = 0

while True:
    guess = ai_guess(low, high)
    guesses += 1
    print(f"\nMy guess #{guesses}: {guess}")
    feedback = input("Is it (H)igh, (L)ow, or (C)orrect? ").lower()

    if feedback == 'c':
        print(f"\nYay! I found your number in {guesses} guesses! 🎉")
        break
    elif feedback == 'h':
        high = guess - 1
    elif feedback == 'l':
        low = guess + 1
    else:
        print("Invalid input! Please type H, L, or C.")

    if low > high:
        print("\nWait... that’s impossible 😅 Are you sure you didn’t cheat?")
        break
