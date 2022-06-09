import "chart.js/auto";
import { Chart } from "react-chartjs-2";

const CircleChart = () => {
    const pieChartData = {
        labels: ["Отлично", "Хорошо", "Удовлетворительно", "Плохо"],
        datasets: [
            {
                data: [1, 2, 3, 4],
                label: "Успеваемость",
                backgroundColor: [
                    "rgb(51, 255, 0)",
                    "rgb(246, 255, 0)",
                    "rgb(0, 145, 255)",
                    "rgb(255, 60, 0)",
                ],
                hoverBackgroundColor: [
                    "rgb(51, 255, 0)",
                    "rgb(246, 255, 0)",
                    "rgb(0, 145, 255)",
                    "rgb(255, 60, 0)",
                ],
            },
        ],
    };

    return (
        <div style={{"marginTop": "50px"}}>
            <Chart
                type="pie"
                width={500}
                height={500}
                options={{
                    title: {
                        display: true,
                        fontSize: 25,
                    },
                    legend: {
                        display: true, //Is the legend shown?
                        position: "left", //Position of the legend.
                    },
                }}
                data={pieChartData}
            />
        </div>
    );
};

export default CircleChart;
