import java.util.*;

public class ShannonCircuits {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Number of gates
        int n = Integer.parseInt(scanner.nextLine().trim());
        Map<String, Gate> gateDefinitions = new LinkedHashMap<>();

        // Reading gate definitions
        for (int i = 0; i < n; i++) {
            String[] parts = scanner.nextLine().trim().split("=");
            String gateName = parts[0].trim();
            String[] gateInfo = parts[1].trim().split("\\(");
            String gateType = gateInfo[0].trim();
            String[] inputs = gateInfo[1].replace(")", "").split(",");
            gateDefinitions.put(gateName, new Gate(gateType, inputs[0].trim(), inputs[1].trim()));
        }

        // Number of cycles
        int t = Integer.parseInt(scanner.nextLine().trim());

        // Reading inputs
        Map<String, int[]> inputSignals = new HashMap<>();
        String line;
        while (!(line = scanner.nextLine().trim()).equals("") && scanner.hasNextLine()) {
            String[] parts = line.split("\\s+");
            String inputName = parts[0];
            int[] values = new int[t];
            for (int i = 0; i < t; i++) {
                values[i] = Integer.parseInt(parts[i + 1]);
            }
            inputSignals.put(inputName, values);
            
            // Check if the next line might be the target gate
            if (!scanner.hasNextLine()) break;
            String nextLine = scanner.nextLine();
            if (!nextLine.contains("=")) {
                line = nextLine;
                break;
            }
            scanner.reset();
        }

        // Target gate
        String targetGate = line.trim();

        // Simulate the circuit
        int[] result = simulateCircuit(gateDefinitions, inputSignals, t, targetGate);
        
        // Print result with spaces between numbers
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            output.append(result[i]);
            if (i < result.length - 1) {
                output.append(" ");
            }
        }
        System.out.println(output.toString());
    }

    private static int[] simulateCircuit(Map<String, Gate> gateDefinitions,
                                       Map<String, int[]> inputSignals, int numCycles, String targetGate) {
        Map<String, int[]> outputs = new HashMap<>();

        // Initialize outputs for gates with 0s
        for (String gate : gateDefinitions.keySet()) {
            outputs.put(gate, new int[numCycles]);
            // All gates start with output 0
            Arrays.fill(outputs.get(gate), 0);
        }

        // For each cycle, compute the next cycle's outputs
        for (int cycle = 0; cycle < numCycles - 1; cycle++) {
            for (String gate : gateDefinitions.keySet()) {
                Gate gateInfo = gateDefinitions.get(gate);
                
                // Get input values from the current cycle
                int value1 = inputSignals.containsKey(gateInfo.input1) ? 
                    inputSignals.get(gateInfo.input1)[cycle] : 
                    outputs.get(gateInfo.input1)[cycle];
                    
                int value2 = inputSignals.containsKey(gateInfo.input2) ? 
                    inputSignals.get(gateInfo.input2)[cycle] : 
                    outputs.get(gateInfo.input2)[cycle];

                // Store result in next cycle
                outputs.get(gate)[cycle + 1] = evaluateGate(gateInfo.type, value1, value2);
            }
        }

        return outputs.get(targetGate);
    }

    private static int evaluateGate(String gateType, int input1, int input2) {
        switch (gateType) {
            case "AND":
                return (input1 == 1 && input2 == 1) ? 1 : 0;
            case "OR":
                return (input1 == 1 || input2 == 1) ? 1 : 0;
            case "NAND":
                return (input1 == 1 && input2 == 1) ? 0 : 1;
            case "NOR":
                return (input1 == 1 || input2 == 1) ? 0 : 1;
            case "XOR":
                return (input1 != input2) ? 1 : 0;
            default:
                throw new IllegalArgumentException("Invalid gate type: " + gateType);
        }
    }

    private static class Gate {
        String type;
        String input1;
        String input2;

        Gate(String type, String input1, String input2) {
            this.type = type;
            this.input1 = input1;
            this.input2 = input2;
        }
    }
}