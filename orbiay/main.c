
#include "../cub3d.h"
#include<string.h>
int strcmp(const char *s1, const char *s2) {
    if(!s1 || !s2)
    {
        printf("STRCMP \n");
        return 1;
    }
   while (*s1 != '\0' && *s2 != '\0'  && *s1 == *s2) {
      s1++;
      s2++;
   }
   return *s1 - *s2;
}

int check_F_C(char **str,int line)
{
    static int F;
    static int C;

    if (check_F(str))
        F++;
    else if(check_C(str))
        C++;
    else if (F > 1 || C > 1)
    {
        printf("Error Map : Duplicate.");
        return 0;
    }
    if (line == 5 && (C == 0 || F == 0))
    {
        printf("Error : Problem in Color .");
        return 0;
    }
    return 1;
}

void ft_free(char **str)
{
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str[i]);
}

int check_Textures(char **str,int line)
{
    static int NO;
    static int SO;
    static int WE;
    static int EA;

    if (strcmp(str[0],"NO") && strcmp(str[0],"SO") 
    && strcmp(str[0],"WE") && strcmp(str[0],"EA") 
    && strcmp(str[0],"F") && strcmp(str[0],"C"))
    {
        printf("Error : Textures or Colors undefined.");
        return (0);
    }
    if(check_NO(str))
        NO++;
    else if(check_SO(str))
        SO++;
    else if(check_WE(str))
        WE++;
    else if(check_EA(str))
        EA++;
    else if(NO > 1 || SO > 1 || WE > 1 || EA > 1)
    {
        printf("Error Map : Duplicate.");
        return 0;
    }
    else if (line == 5 && (NO == 0 || SO == 0 || WE == 0 || EA == 0))
    {
        printf("Error Map : Something Wrong");
        return 0;
    }
    return check_F_C(str,line);
}

int  first_six_lines(char *split_str,int line)
{

    char *str = ft_strdup(split_str);
    char **split = ft_split(str,' ');
    if (!check_Textures(split,line))
    {
        ft_free(split);
        free(str);
        return 0;
    }
    ft_free(split);
    free(str);
    return 1;
}

int map_checking(char *str)
{
    char **split_str = ft_split(str,'\n');
    int i = 0;
    while (i < 6)
    {
        if (!first_six_lines(split_str[i],i))
        {
            ft_free(split_str);
            return 0;
        }
        i++;
    }
    ft_free(split_str);
    return 1;
}
int req_space(char **str,int start,int i)
{
    int count = 0;
    if (!str[start + 1])
        count++;
    int len = ft_strlen(str[start + 1]);
    printf("1\n");
    if ( str[start][i + 1]&& str[start][i + 1] != ' ' &&  str[start][i + 1] != '1')
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start ,i);
        return 0;
    }
    printf("2\n");
    if (i > 0 && str[start][i - 1] != ' ' &&  str[start][i - 1] != '1')
    {
         printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    printf("3\n");
    //if(!count && str[start + 1][i] && str[start + 1][i] != ' ' && str[start + 1][i] != '1')
    //{
    //    printf("Error Map : U have Problem in Row[%d][%d].",start,i);
    //    return 0;
    //}
    //printf("len=  %d && i = %d\n",len,i);
    if (i < len - 1 && str[start + 1] && str[start + 1][i] && str[start + 1][i] != ' ' && str[start + 1][i] != '1')
    {
        printf("c=  %c\n",str[start + 1][i]);
        printf("3Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    printf("4\n");
    printf("starrrt =  %d\n",start);
    if(start > 6 && str[start - 1] && str[start - 1][i] && str[start - 1][i] != ' ' && str[start - 1][i] != '1' )
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    printf("5\n");
    return 1;
}

int check_player(char str){
        if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
            return 1;
    return 0;
}

int req_zero(char **str,int start, int i)
{
    int count = 0;
    if (!str[start + 1])
        count++;
    //printf("1Im here\n");
    if (str[start][i + 1] && str[start][i + 1] != '0' && !check_player(str[start][i + 1]) && str[start][i + 1] != '1')
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    //printf("2Im here\n");
    if (str[start][i - 1] && str[start][i - 1] != '0' && str[start][i - 1] != '1' && !check_player(str[start][i - 1]))
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    //printf("4Im here\n");
    if ((!str[start + 1][i]) || (str[start + 1][i] && str[start + 1][i] != '0' && !check_player(str[start + 1][i]) && str[start + 1][i] != '1'))
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    //printf("3Im here\n");
    if ((!str[start - 1][i]) ||(str[start - 1][i] && str[start - 1][i] != '0' && !check_player(str[start - 1][i]) && str[start - 1][i] != '1'))
    {
        printf("Error Map : U have Problem in Row[%d][%d].",start,i);
        return 0;
    }
    return 1;
}



int check_spaces(char **str,int start)
{
    int j = 0;
    int count = counting(str);
    while (str[start])
    {   
        //str[start] = check_player(str[start]);
     //printf("start = %d\n",start);
        j = 0;
        if (!check_Walls(str[start],start,count))
            return 0;
        while (str[start][j])
        {
            //if (str[start][j] == ' ' && !req_space(str,start,j))
            //    return 0;
            if (str[start][j] == '0' && !req_zero(str,start,j))
                return 0;
            j++;
        }
        //str[start] = return_it(str[start]);
        start++;
    }
    return 1;
}


int last_touches(char **str)
{
	int count_0 = 0;
	int cout_P = 0;
	int i = 6;
	int j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
				count_0++;
			if (check_player(str[i][j]))
				cout_P++;
			j++;
		}
		i++;
	}
	if (count_0 == 0 || (cout_P == 0 || cout_P > 1) || i == 6)
	{
		printf("cout_p = %d\n",cout_P);
		printf("Error : There is a problem");
		return 0;
	}
	return 1;
}

int map_checking2(char *str)
{
    char **split_str = ft_split(str,'\n');
    int statrt = 6;
    if(!check_spaces(split_str,statrt))
        return 0;
	if (!last_touches(split_str) )
		return 0;
    return 1;
}
t_fd file_dis(char *sp,char *s)
{
    t_fd fd;
    if (!strcmp(sp,"NO"))
        fd.NO = ft_strdup(s);
    else if (!strcmp(sp,"SO"))
        fd.SO = ft_strdup(s);
    else if (!strcmp(sp,"WE"))
        fd.WE = ft_strdup(s);
    else if (!strcmp(sp,"EA"))
        fd.EA = ft_strdup(s);
    else if (!strcmp(sp,"F"))
        fd.F = ft_strdup(s);
    else if (!strcmp(sp,"C"))
        fd.C = ft_strdup(s);
    return fd;
}
t_fd take_path(char *str)
{
        
    char **str_sp = ft_split(ft_strdup(str),'\n');
    t_fd fd;
    int i = 0;
    while (i < 6)
    {
        char **sp = ft_split(ft_strdup(str_sp[i]),' ');
        char *s = joining(sp);
        fd = file_dis(sp[0],s);
        ft_free(sp);
        free(s);
        i++;
    }
    return fd;
}

int check_isdigit(char **sp)
{
	int i = 0;
	int j = 0;
	while (sp[i])
	{
		j = 0;
		int num = ft_atoi(sp[i]);
		if (num > 255 || num < 0)
		{
			printf("Error :Colors  %s High Than 255\n",sp[i]);
			return 0;
		}
		i++;
	}
	return	1;
}

int check_Colors_valid(char *F,char *C)
{
    char **sp_f = ft_split(ft_strdup(F),',');
    char **sp_c = ft_split(ft_strdup(C),',');
    if(counting(sp_f) != 3 || counting(sp_c) != 3)
    {
        printf("Error : There is problem in COLORS.");
		ft_free(sp_f);
		ft_free(sp_c);
        return 0;
    }
    if(!check_isdigit(sp_f) || !check_isdigit(sp_c))
	{
		ft_free(sp_f);
		ft_free(sp_c);
        return 0;
	}
	ft_free(sp_f);
	ft_free(sp_c);
    return 1;
}


t_fd read_and_add(char **av)
{
    int fd = open("map.txt",O_RDONLY);
    char *str = NULL;
    char *buf = get_next_line(fd);
    t_fd fd2;
    
    while (buf)
    {
        str = ft_strjoin(str,buf);
        free(buf);
        buf = get_next_line(fd);
        //free(buf);
    }
    free(buf);
	if (!str)
	{
		printf("Error : Map invalid");
		exit(1);
	}
    fd2.full_map = ft_strdup(str);
    if (map_checking(str))
    {
        fd2 = take_path(str);
       if (!map_checking2(str) || !check_Colors_valid(fd2.F,fd2.C))
            exit(0);
        printf("\nALL thing is valid\n");
    }
    return fd2;
}
// int main (int ac , char **av)//map with '\n'
// {
//     t_fd fd2;
//     fd2 = read_and_add(av);
//     return (0);
// }