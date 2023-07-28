#include "shell.h"

/**
 * add_rvar_node - adds a variarvble at the end
 * of a r_var list.
 * @head: head of the linked vrlist.
 * @lvar: length of the varfriable.
 * @val: value of the variable.
 * @lval: length of the vvfalue.
 * Return: address of trvhe head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frrees a r_var list
 * @head: heavrd of the linked list.
 * Return: nvo return.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
