#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_mouvement
{
	void				*content;
	struct s_mouvement	*next;
}	t_mvt;

/*check_arg*/
int			str_is_not_nbr(char *str);
int			check_arg(int ac, char **av);
int			check_doublons(char **tab);
int			hors_int(char *str);
char		*remplace(char *str, char *liste);
/*math_tools*/
t_list		*find_max(t_list *lst);
t_list		*find_min(t_list *lst);
int			find_mediane(t_list *lst);
/*cout*/
t_list		*coutmin_putop(t_list *lst, int mediane);
t_list		*find_pos_a(t_list *elem, t_list *lst);
t_mvt		*mvt_min(t_list *lst_a, t_list *lst_b, int min_mvt);
void		sort_smart(t_list **lst_a, t_list **lst_b);
/*ft_libft*/
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
/*libft_lst*/
t_list		*t_ft_lstnew(int value);
void		t_ft_lstadd_back(t_list **alst, t_list *new);
int			t_ft_lstsize(t_list *lst);
t_list		*t_ft_lstlast(t_list *lst);
void		t_ft_lstclear(t_list **lst);
/*libft_m_lst*/
void		ft_lstadd_back(t_mvt **alst, t_mvt *new);
void		ft_lstclear(t_mvt **lst);
t_mvt		*ft_lstlast(t_mvt *lst);
t_mvt		*ft_lstnew(void *content);
int			ft_lstsize(t_mvt *lst);
/*action*/
void		swap(t_list *lst);
void		push_top(t_list **lst_send, t_list **lst_receive);
void		rotate_lst(t_list **lst);
void		reverse_lst(t_list **lst);
/*sort_short*/
int			sort_short(t_list **lst);
int			sort_short_2(t_list **lst);
int			sort_short_3(t_list **lst);
int			sort_hard(t_list **lst);
/*sort_medium*/
int			sort_medium_mediane(t_list **lst);
int			sort_medium(t_list **lst);
t_mvt		*mvt_totop_b(t_list *elem, t_list **lst);
t_mvt		*mvt_totop_a(t_list *elem, t_list **lst);
void		execute_mvt(t_list **lst_a, t_list **lst_b, t_mvt *mvt);
/*optimize*/
t_mvt		*optimize_rr(t_mvt *mvt);
t_mvt		*optimize_rr_2(t_mvt *mvt, int i);
t_mvt		*optimize_rrr(t_mvt *mvt);
t_mvt		*optimize_rrr_2(t_mvt *mvt, int i);
t_mvt		*optimize(t_mvt *mvt);
/*tools_lst*/
void		send_top(t_list *elem, t_list **lst);
void		print_mvt(t_mvt *mvt);
/*utils_check*/
int			lst_sorted(t_list *lst);
int			lst_inverse(t_list *lst);
int			check_pos(t_list *lst, int nb);
/*ft_split*/
char		**ft_split(char const *s, char c);
/*push_swap*/
void		free_tab(char **tab);
int			message_error(int ac, char **tab);
int			solver(t_list *lst_a);

#endif
