   M S B A M L   `   `   `  ����C  ?QuizzIUT, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null#clr-namespace:QuizzIUTQuizzIUT  5   	       QuizzIUT.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   (localclr-namespace:QuizzIUT     5   	   -   5          �Name$  WNDFenetrePrincipale��5   	    � Title$ 
MainWindow��5   	   $	��412��6   $	��800��6)   .��5	      �  J� RenderTransformOrigin$ 0.762,0.427&�6    � ColumnDefinitions 5
   
   �� 5      $
��232* �6   �� 5      $
��397* �6   �� 5      $
��171* �6   .+�5   
   �� -   5         ��Name$ LBLTitre��5      $��Questions pour un BUT ��6"   $
��Left=�6C   $��	10,10,0,0q�6^   $	��Top=�6q   $��36(�6�   $��62��6�   $	��410��6�   $
��Bold"�6�   $��Source Sans Pro Black)�6�   $��2��6�   �� 5   
   -   5        $ LBLQuestion��5      $!��Insérez votre question ici��6%   $
��Left=�6J   $��	23,83,0,0q�6e   $	��Top=�6x   $��20(�6�   $��2��6�   $��47��6�   �� 5   
   -   5         ��Name$ 
TBXReponse��5      $
��Left=�6&   $��
81,155,0,0q�6A    �� TextWrapping$
 Wrap=�6U   $	��Top=�6i   $	��226��6�   $��18��6�   $��2��6�   �� 5   
   -   5         ��Name$ 
BTNValider��5      $��Valider��6%   $
��Left=�67   $��120,150,0,0q�6R   $	��Top=�6g   $��28��6�   $��44��6�   $ -0.091,-0.498&�6�   $��1��6�   �� 5   
   -   5        $ LBLBonneRéponses��5      $��Bonnes réponses :��6*   $
��Left=�6F   $��
77,198,0,0q�6a   $	��Top=�6u   �� 5   
   -   5        $! LBLMauvaisesReponsesValeurs��5      $��0��65   $
��Left=�6A   $��199,238,0,0q�6\   $	��Top=�6q   �� 5   
   -   5        $ LBLBonneRéponsesValeurs��5      $��0��61   $
��Left=�6=   $��182,198,0,0q�6X   $	��Top=�6m   $ 
5.201,2.57&�6�   �� 5   
   -	   5        $ LBLMauvaisesRéponses��5      $��Mauvaises réponses :��6.   $
��Left=�6M   $��
77,238,0,0q�6h   $	��Top=�6|   �� 5   
   -
   5         ��Name$ SDRModeNuit��5      $
��Left=�6&   $��
379,91,0,0q�6A   $	��Top=�6U   $��73��6m   	 � Maximum$	 1Q�6x   $��1��6�   $��2��6�   �� 5   
   -   5        
 ��Name$
 IMGMoon��5      $��0,83,0,0q�6!   $��	/moon.png��63   $
��Fill=�6F   $��Center=�6U   $	��Top=�6r   $��34��6�   $��36��6�   $��2��6�   �� 5   
   -   5        $
 	IMGSoleil��5      $��
312,75,0,0q�6#   $��/sun.png��67   $
��Fill=�6I   $
��Left=�6X   $	��Top=�6s   $��50��6�   $��53��6�   $��1��6�   5      5      