/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:46:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/11 16:05:16 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void	sab(t_node **head)
{
	t_node	*temp;

	if (!head || !(*head)->next)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	return ;
}
void	pab(t_node **head1, t_node **head2)
{
	t_node	*temp;

	if (!head1)
		return ;
	temp = *head1;
	*head1 = (*head1)->next;
	temp->next = *head2;
	*head2 = temp;
	return ;
}
void	rab(t_node **head)
{
	t_node	*temp;
	t_node	*temp2;

	if (!head || !(*head)->next)
		return ;
	temp2 = *head;
	temp = *head;
	while (temp->next->next != NULL)
		temp = temp->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp->next = NULL;
	temp2->next = *head;
	*head = temp2;
	return ;
}
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
// buradan sonrasını ben yazmadım

void	print_stack(char *name, t_node *head)
{
	printf("%s: ", name);
	while (head)
	{
		printf("[%d] ", head->value);
		head = head->next;
	}
	printf("\n");
}
int	main(void)
{
	t_node *a = new_node(3);
	a->next = new_node(1);
	a->next->next = new_node(2);
	t_node *b = NULL;

	printf("--- Başlangıç ---\n");
	print_stack("A", a);
	print_stack("B", b);

	printf("\n--- pb ---\n");
	pab(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	printf("\n--- sa ---\n");
	sab(&a);
	print_stack("A", a);
	print_stack("B", b);
	printf("\n--- rra ---\n");
	rab(&a);
	print_stack("A", a);
}