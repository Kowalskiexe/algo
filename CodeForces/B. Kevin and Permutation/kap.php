#!/usr/bin/env php
<?php
    fscanf(STDIN, "%d", $t);
    for ($i = 0; $i < $t; $i++) {
        fscanf(STDIN, "%d", $n);
        if ($n % 2 == 0) {
            $h = $n / 2;
            $el = $h;
            for ($j = 0; $j < $n; $j++) {
                echo "$el ";
                if ($j % 2 == 0)
                    $el += $h;
                else
                    $el -= $h + 1;
            }
        } else {
            $h = intdiv($n, 2);
            $el = $h + 1;
            for ($j = 0; $j < $n; $j++) {
                echo "$el ";
                if ($j % 2 == 0)
                    $el += $h;
                else
                    $el -= $h + 1;
            }
        }
        echo "\n";
    }
?>
