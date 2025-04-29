#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>



char users[5][20] = { "user1", "user2", "user3", "user4", "user5" };
char passwords[5][20] = { "pass1", "pass2", "pass3", "pass4", "pass5" };
int has_voted[5] = { 0,0,0,0,0 };
char candidates[3][20] = { "Muhammad Ali","Muhammad Hussain", "Muhammad Hasssan" };
int votes[3] = { 0,0,0 };

// Function to handle user login
int login() {
	char id[20];
	char pass[20];

	printf("Enter Your User_name : \n ");
	scanf("%s", id);
	printf("Enter Your Password: \n");
	scanf("%s", pass);
	// Check if the user exists and password is correct
	for (int i = 0; i < 5; i++) {
		if (strcmp(id, users[i]) == 0 && strcmp(pass, passwords[i]) == 0) {
			return i;
		}
	}
	// If user not found or password is incorrect
	printf("Invalid User_name Or Password\n");
	return -1;

}
// to check if user has already voted
int voted(int user_index) {
	// Check if the user has already voted
	if (has_voted[user_index] == 1) {
		printf("Your have already voted\n");
		return 1;
	}

	return 0;
}
// Function to handle voting
void voting(int user_index) {
	int choice;
	// Display candidates and Vote
	printf("Candidates:\n");
	for (int i = 0; i < 3; i++) {
		printf("%d,%s\n", i + 1, candidates[i]);
	}
	printf("Press 1 - 3 for your desired candidates:");
	scanf("%d", &choice);
	// Check if the choice is valid
	if (choice < 1 || choice > 3) {
		printf("Invalid choice\n");
		return;
	}
	// Increment the vote count for the chosen candidate
	votes[choice - 1]++;
	has_voted[user_index] = 1;
	printf("You have voted for %s\n", candidates[choice - 1]);
}
// Function to display results
void display_results() {
	printf("results:\n");
	// Display the results
	for (int i = 0; i < 3; i++)
	{
		printf("%s: %d\n", candidates[i], votes[i]);
	}
}
// Main function
int main() {
	int user_index;
	int total_voters = 5;  // Total number of users
	int remaining_voters = total_voters;  // Tracks remaining users who need to vote

	// Continue asking users to vote until all have voted
	while (remaining_voters > 0) {
		user_index = login();  

		// Check if the user is valid
		if (user_index == -1) {
			continue;  // If login fails, ask the user again
		}

		// Check if the user has already voted
		if (voted(user_index)) {
			continue;  // Skip voting for the user who has already voted
		}

		// If the user is valid and has not voted, proceed to voting
		voting(user_index);
		remaining_voters--;  // Decrease the remaining voters count
	}

	// All users have voted, display the results
	printf("\nAll users have voted!\n");
	display_results();

	return 0;

}