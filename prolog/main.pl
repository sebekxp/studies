check(P) :-
    % Z predykatów o  numerach: 4, 6, 8, 11, 15 ,16 mo¿emy zadeklarowaæ nastêpuj¹c¹ liste: P = [[_,Pietro, Zwierze]...]
    % Dziêki temu nie bêdziemy musieli u¿ywaæ podczas rozwi¹zywania problemu predykatów okreœlaj¹cych
    % po³o¿enie wzgledem siebie(np. A wy¿ej/ni¿ej ni¿ B).

    % P = [[Imie, Piêtro, Zwierze], ...]
    P = [[_, 0, w¹¿],
         [_, 1, kanarek],
         [_, 2, pies],
         [_, 3, rybka],
         [_, 4, chomik],
         [_, 5, kot],
         [_, 6, papuga]
        ],

    member([szymon, _, SzZw], P), SzZw \== papuga,    % 1. Szymon nie ma papugi.
    member([marcin, _, MZw], P), MZw \== w¹¿,         % 9. Marcin nie ma wê¿a.
    member([robert, _, RZw], P), RZw \== papuga,      % 12. Robert nie ma papugi.
    member([robert, _, RZw], P), RZw \== kanarek,     % 13. Robert nie ma kanarka.
    member([stefan, _, SZw], P), SZw \== rybka,       % 19. Stefan nie ma rybki.
    member([robert, _, RZw], P), RZw \== pies,        % 20. Robert nie ma psa.
    member([albert, _, AZw], P), AZw \== w¹¿,         % 22. Albert nie ma wê¿a.
    member([robert, _, RZw], P), RZw \== kot,         % 23. Robert nie ma kota.
    member([franek, _, FZw], P), FZw \== pies,        % 27. Franek nie ma psa.
    member([jarek, _, JZw], P), JZw \== rybka,        % 28. Jarek nie ma rybki.
    member([franek, _, FZw], P), FZw \== papuga,      % 29. Franek nie ma papugi.
    member([marcin, _, MZw], P), MZw \== kot,         % 34. Marcin nie ma kota.
    member([marcin, _, MZw], P), MZw \== kanarek,     % 35. Marcin nie ma kanarka.
    member([marcin, _, MZw], P), MZw \== papuga,      % 39. Marcin nie ma papugi.
    member([robert, _, RZw], P), RZw \== w¹¿,         % 43. Robert nie ma wê¿a.
    member([szymon, _, SzZw], P), SzZw \== kanarek,   % 44. Szymon nie ma kanarka.
    member([robert, _, RZw], P), RZw \== rybka,       % 45. Robert nie ma rybki.
    member([jarek, _, JZw], P), JZw \== pies,         % 46. Jarek nie ma psa.
    member([albert, _, AZw], P), AZw \== pies,        % 47. Albert nie ma psa.
    member([szymon, _, SzZw], P), SzZw \== chomik,    % 48. Szymon nie ma chomika.
    member([albert, _, AZw], P), AZw \== chomik,      % 49. Albert nie ma chomika.
    member([stefan, _, SZw], P), SZw \== w¹¿,         % 50. Stefan nie ma wê¿a.
    member([marcin, _, MZw], P), MZw \== chomik,      % 51. Marcin nie ma chomika.
    member([franek, _, FZw], P), FZw \== kanarek,     % 52. Franek nie ma kanarka.
    member([marcin, _, MZw], P), MZw \== pies,        % 53. Marcin nie ma psa.
    member([jarek, _, JZw], P), JZw \== w¹¿,          % 54. Jarek nie ma wê¿a.
    member([franek, _, FZw], P), FZw \== kot,         % 55. Franek nie ma kota.
    member([franek, _, FZw], P), FZw \== chomik,      % 56. Franek nie ma chomika.
    member([szymon, _, SzZw], P), SzZw \== w¹¿,       % 57. Szymon nie ma wê¿a.
    member([jarek, _, JZw], P), JZw \== kot,          % 58. Jarek nie ma kota.
    member([albert, _, AZw], P), AZw \== kot,         % 59. Albert nie ma kota.
    member([jarek, _, JZw], P), JZw \== papuga,       % 60. Jarek nie ma papugi.
    member([jarek, _, JZw], P), JZw \== chomik,       % 61. Jarek nie ma chomika.
    member([franek, _, FZw], P), FZw \== rybka,       % 62. Franek nie ma rybki.
    member([stefan, _, SZw], P), SZw \== chomik,      % 63. Stefan nie ma chomika.
    member([stefan, _, SZw], P), SZw \== pies.        % 64. Stefan nie ma psa.



    U¿ycie:    ?- check(P)
    P = [[franek, 0, w¹¿],
         [jarek, 1, kanarek],
         [szymon, 2, pies],
         [marcin, 3, rybka],
         [robert, 4,    chomik],
         [stefan, 5, kot],
         [albert, 6, papuga]]