<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>
            Máy tính
        </title>
    </head>
    <body>
        <form action=# method="POST" name="formCalc">
            <table width=600   class="calc">
                <tr>
                    <td>Số A</td>
                    <td>
                        <input type="number" name="numa" class="form-control" required>
                    </td>
                </tr>
                <tr>
                    <td>Số B</td>
                    <td>
                        <input type="number" name="numb" class="form-control" required>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <input type="checkbox" name="calc[]" value="+" class="form-control">
                        <label for="plus">Cộng</label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <input type="checkbox" name="calc[]" value="-" class="form-control">
                        <label for="minus">Trừ</label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <input type="checkbox" name="calc[]" value="*" class="form-control">
                        <label for="multiply">Nhân</label>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <input type="checkbox" name="calc[]" value="/" class="form-control">
                        <label for="divine">Chia</label>
                    </td>
                </tr>
                <tr>
                    <td>
                        <button type="submit" class="form-control">Tính</button>
                    </td>
                    <td>
                        <button type="reset" class="form-control">Xoá</button> 
                    </td>
                </tr>
                <tr>
                    <td>
                        Kết quả: 
                    </td>
                </tr>
            </table>
        </form>
        <?php
            
            if (isset($_POST["numa"]) && isset($_POST["numb"]) && isset($_POST["calc"])){
                $a=$_POST["numa"];
                $b=$_POST["numb"];
                $calc=$_POST["calc"];

                echo "<table width=200>";
                for($i=0;$i<count($calc);$i++){
                    switch ($calc[$i]){
                        case "+":
                            echo "<tr>";
                                echo "<td>";
                                    echo "Cộng:";
                                echo "<td/>";
                                echo "<td>";
                                    echo $a+$b;
                                echo "<td/>";
                            echo "<tr/>";
                        break;
                        case "-":
                            echo "<tr>";
                                echo "<td>";
                                    echo "Trừ:";
                                echo "<td/>";
                                echo "<td>";
                                    echo $a-$b;
                                echo "<td/>";
                            echo "<tr/>";
                        break;
                        case "*":
                            echo "<tr>";
                                echo "<td>";
                                    echo "Nhân:";
                                echo "<td/>";
                                echo "<td>";
                                    echo $a*$b;
                                echo "<td/>";
                            echo "<tr/>";
                        break;
                        case "/":
                            echo "<tr>";
                                echo "<td>";
                                    echo "Chia:";
                                echo "<td/>";
                                echo "<td>";
                                    echo $a/$b;
                                echo "<td/>";
                            echo "<tr/>";
                        break;
                    }
                }
                echo "<table/>";
            }
        ?>
    </body>
</html>