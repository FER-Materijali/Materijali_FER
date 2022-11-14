package hr.fer.oop.lab6.prob1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Predicate;
import java.util.stream.*;
import java.awt.*;
import java.io.*;
import java.nio.file.*;
import javax.swing.*;

/**
 * The Class GenericTableMain.
 */
public class GenericTableMain {

	/** The record list. */
	private static List<TaxiRecord> recordList = new ArrayList<>();

	/** The table panel. */
	private static GenericTablePanel<TaxiRecord> tablePanel = new GenericTablePanel<>(TaxiRecord.class);

	/** The apply filter. */
	private static JButton load, exit, defineFilter, applyFilter;

	/** The text path. */
	private static JTextArea textPath;

	/** The filter definer. */
	private static FilterDefiner filterDefiner;

	/** The instance. */
	private static GenericTableMain instance;

	/**
	 * Gets the single instance of GenericTableMain.
	 *
	 * @return single instance of GenericTableMain
	 */
	private static GenericTableMain getInstance() {
		if (instance == null)
			instance = new GenericTableMain();
		return instance;
	}

	/**
	 * The main method.
	 *
	 * @param args
	 *            the arguments
	 * @throws Exception
	 *             the exception
	 */
	public static void main(String[] args) throws Exception {
		filterDefiner = new FilterDefiner();

		SwingUtilities.invokeAndWait(() -> {
			JFrame window = new JFrame();
			window.setLocation(20, 20);
			window.setSize(500, 220);
			window.setVisible(true);
			window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
			window.setTitle("Taxi Record Viewer");
			tablePanel.setPreferredSize(new Dimension(200, 100));
			window.add(tablePanel, BorderLayout.CENTER);

			JPanel logPanel = new JPanel();
			JTextArea log = new JTextArea();
			JScrollPane scroll = new JScrollPane(log);
			scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
			log.setVisible(true);
			log.setRows(3);
			log.setMaximumSize(logPanel.getSize());
			log.setEditable(false);
			logPanel.add(scroll);
			PrintStream printStream = new PrintStream(new CustomOutputStream(log));
			System.setOut(printStream);
			System.setErr(printStream);

			JToolBar toolbar = new JToolBar();

			exit = new JButton("Exit");
			exit.addActionListener(e -> System.exit(0));

			load = new JButton("Load file");
			load.addActionListener(e -> {
				load.setEnabled(false);
				GetDataAsync getData = new GetDataAsync(textPath.getText());
				getData.start();
			});

			defineFilter = new JButton("Define Filter");
			defineFilter.addActionListener(e -> {
				filterDefiner.setVisible(!filterDefiner.isVisible());
			});

			applyFilter = new JButton("Apply Filter");
			applyFilter.addActionListener(e -> {
				applyFilter.setEnabled(false);
				FilterDataAsync filterData = new FilterDataAsync(tablePanel.getRecords());
				filterData.start();
			});

			textPath = new JTextArea();
			textPath.setPreferredSize(new Dimension(420, 10));

			toolbar.add(exit);
			toolbar.add(textPath);
			toolbar.add(load);
			toolbar.add(defineFilter);
			toolbar.add(applyFilter);

			window.add(toolbar, BorderLayout.PAGE_START);
			window.add(logPanel, BorderLayout.AFTER_LAST_LINE);

			tablePanel.setPreferredSize(new Dimension(200, 100));
			window.add(tablePanel, BorderLayout.CENTER);

			window.pack();
		});

	}

	/**
	 * The Class GetDataAsync.
	 */
	private static class GetDataAsync extends Thread {

		/** The path. */
		private String path;

		/**
		 * Instantiates a new gets the data async.
		 *
		 * @param path
		 *            the path
		 */
		public GetDataAsync(String path) {
			this.path = path;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Thread#run()
		 */
		@Override
		public void run() {
			try {
				final AtomicInteger i = new AtomicInteger(1);
				recordList = Files.lines(Paths.get(path)).map(line -> line.split(",")).distinct()
						.map(line -> getInstance().new TaxiRecord(i.getAndAdd(1), line[0], line[1], line[2], line[3],
								line[4], line[5], line[6], line[7], line[8], line[9], line[10], line[11], line[12],
								line[13], line[14], line[15], line[16]))
						.collect(Collectors.toList());
			} catch (IOException | InvalidPathException e) {
				System.err.println(String.format("File %s does not exist.", path));
			} finally {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						load.setEnabled(true);
						tablePanel.update(recordList);
					}
				});
			}
		}
	}

	/**
	 * The Class FilterDataAsync.
	 */
	private static class FilterDataAsync extends Thread {

		/** The records in table list. */
		private List<TaxiRecord> recordsInTableList;

		/**
		 * Instantiates a new filter data async.
		 *
		 * @param recordsInTableList
		 *            the records in table list
		 */
		public FilterDataAsync(List<TaxiRecord> recordsInTableList) {
			this.recordsInTableList = recordsInTableList;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Thread#run()
		 */
		@Override
		public void run() {
			try {
				FilterData filter = filterDefiner.getFilterData();

				if (filter.isTotalMiles()) {
					List<String> taxiLicenses = new ArrayList<>();
					Map<String, Double> totalDistances = new HashMap<>();
					Map<String, List<TaxiRecord>> occurrences = recordsInTableList.stream()
							.collect(Collectors.groupingBy(taxi -> taxi.getHashLicense()));

					for (Map.Entry<String, List<TaxiRecord>> entry : occurrences.entrySet()) {
						for (TaxiRecord t : entry.getValue()) {
							double current = totalDistances.get(entry.getKey()) == null ? 0
									: totalDistances.get(entry.getKey());
							totalDistances.put(entry.getKey(), current + t.getDistance());
						}
					}

					for (Map.Entry<String, Double> entry : totalDistances.entrySet()) {
						if (entry.getValue() == filter.getMiles()) {
							taxiLicenses.add(entry.getKey());
						}
					}

					recordsInTableList.removeIf(t -> !taxiLicenses.contains(t.getHashLicense()));
				}
				if (filter.isSkipRecords()) {
					recordsInTableList = recordsInTableList.stream()
							.filter(record -> (record.getId() >= filter.getSkip())).collect(Collectors.toList());
				}
				if (filter.isLeaveRecords()) {
					recordsInTableList = recordsInTableList.stream()
							.filter(record -> (record.getId() <= filter.getLeave())).collect(Collectors.toList());
				}
				if (filter.isLimitDistance()) {
					recordsInTableList = recordsInTableList.stream().filter(new Predicate<TaxiRecord>() {
						@Override
						public boolean test(TaxiRecord t) {
							switch (filter.getOperator()) {
							case ">":
								return t.getDistance() > filter.getDistance();
							case "<":
								return t.getDistance() < filter.getDistance();
							case "=":
								return t.getDistance() == filter.getDistance();
							default:
								return false;
							}
						}
					}).collect(Collectors.toList());
				}
				if (filter.isFilterByType()) {
					recordsInTableList = recordsInTableList.stream()
							.filter(record -> (record.getPaymentType() == filter.getPaymentType()))
							.collect(Collectors.toList());
				}
			} catch (NumberFormatException e) {
				System.err.println(String.format("Invalid filter %s", e.getMessage()));
			} catch (Exception e) {
				System.err.println(e.getMessage());
			} finally {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						applyFilter.setEnabled(true);
						if (recordsInTableList.size() == 0) {
							JOptionPane.showMessageDialog(null, "No such records", "Error", JOptionPane.ERROR_MESSAGE);
							return;
						}
						tablePanel.update(recordsInTableList);
					}
				});
			}
		}
	}

	/**
	 * The Class TaxiRecord.
	 */
	public class TaxiRecord {

		/** The id. */
		private int id;

		/** The medallion. */
		private String medallion;

		/** The hash license. */
		private String hashLicense;

		/** The pickup time. */
		private String pickupTime;

		/** The drop off time. */
		private String dropOffTime;

		/** The duration. */
		private int duration;

		/** The distance. */
		private double distance;

		/** The p longitude. */
		private double pLongitude;

		/** The p latitude. */
		private double pLatitude;

		/** The d longitude. */
		private double dLongitude;

		/** The d latitude. */
		private double dLatitude;

		/** The payment type. */
		private PaymentType paymentType;

		/** The fare amount. */
		private double fareAmount;

		/** The surchange. */
		private double surchange;

		/** The tax. */
		private double tax;

		/** The tip amount. */
		private double tipAmount;

		/** The tolls amount. */
		private double tollsAmount;

		/** The total amount. */
		private double totalAmount;

		/**
		 * Instantiates a new taxi record.
		 *
		 * @param id
		 *            the id
		 * @param medallion
		 *            the medallion
		 * @param hashLicense
		 *            the hash license
		 * @param pickupTime
		 *            the pickup time
		 * @param dropOffTime
		 *            the drop off time
		 * @param duration
		 *            the duration
		 * @param distance
		 *            the distance
		 * @param pLongitude
		 *            the longitude
		 * @param pLatitude
		 *            the latitude
		 * @param dLongitude
		 *            the d longitude
		 * @param dLatitude
		 *            the d latitude
		 * @param paymentType
		 *            the payment type
		 * @param fareAmount
		 *            the fare amount
		 * @param surchange
		 *            the surchange
		 * @param tax
		 *            the tax
		 * @param tipAmount
		 *            the tip amount
		 * @param tollsAmount
		 *            the tolls amount
		 * @param totalAmount
		 *            the total amount
		 */
		public TaxiRecord(int id, String medallion, String hashLicense, String pickupTime, String dropOffTime,
				String duration, String distance, String pLongitude, String pLatitude, String dLongitude,
				String dLatitude, String paymentType, String fareAmount, String surchange, String tax, String tipAmount,
				String tollsAmount, String totalAmount) {
			this.id = id;
			this.medallion = medallion;
			this.hashLicense = hashLicense;
			this.pickupTime = pickupTime;
			this.dropOffTime = dropOffTime;
			this.duration = Integer.parseInt(duration);
			this.distance = Double.parseDouble(distance);
			this.pLongitude = Double.parseDouble(pLongitude);
			this.pLatitude = Double.parseDouble(pLatitude);
			this.dLongitude = Double.parseDouble(dLongitude);
			this.dLatitude = Double.parseDouble(dLatitude);
			setPaymentType(paymentType);
			this.fareAmount = Double.parseDouble(fareAmount);
			this.surchange = Double.parseDouble(surchange);
			this.tax = Double.parseDouble(tax);
			this.tipAmount = Double.parseDouble(tipAmount);
			this.tollsAmount = Double.parseDouble(tollsAmount);
			this.totalAmount = Double.parseDouble(totalAmount);
		}

		/**
		 * Gets the id.
		 *
		 * @return the id
		 */
		public int getId() {
			return id;
		}

		/**
		 * Gets the medallion.
		 *
		 * @return the medallion
		 */
		public String getMedallion() {
			return medallion;
		}

		/**
		 * Gets the hash license.
		 *
		 * @return the hash license
		 */
		public String getHashLicense() {
			return hashLicense;
		}

		/**
		 * Gets the pickup time.
		 *
		 * @return the pickup time
		 */
		public String getPickupTime() {
			return pickupTime;
		}

		/**
		 * Gets the drop off time.
		 *
		 * @return the drop off time
		 */
		public String getDropOffTime() {
			return dropOffTime;
		}

		/**
		 * Gets the duration.
		 *
		 * @return the duration
		 */
		public int getDuration() {
			return duration;
		}

		/**
		 * Gets the distance.
		 *
		 * @return the distance
		 */
		public double getDistance() {
			return distance;
		}

		/**
		 * Gets the p longitude.
		 *
		 * @return the p longitude
		 */
		public double getpLongitude() {
			return pLongitude;
		}

		/**
		 * Gets the p latitude.
		 *
		 * @return the p latitude
		 */
		public double getpLatitude() {
			return pLatitude;
		}

		/**
		 * Gets the d longitude.
		 *
		 * @return the d longitude
		 */
		public double getdLongitude() {
			return dLongitude;
		}

		/**
		 * Gets the d latitude.
		 *
		 * @return the d latitude
		 */
		public double getdLatitude() {
			return dLatitude;
		}

		/**
		 * Gets the payment type.
		 *
		 * @return the payment type
		 */
		public PaymentType getPaymentType() {
			return paymentType;
		}

		/**
		 * Gets the fare amount.
		 *
		 * @return the fare amount
		 */
		public double getFareAmount() {
			return fareAmount;
		}

		/**
		 * Gets the surchange.
		 *
		 * @return the surchange
		 */
		public double getSurchange() {
			return surchange;
		}

		/**
		 * Gets the tax.
		 *
		 * @return the tax
		 */
		public double getTax() {
			return tax;
		}

		/**
		 * Gets the tip amount.
		 *
		 * @return the tip amount
		 */
		public double getTipAmount() {
			return tipAmount;
		}

		/**
		 * Gets the tolls amount.
		 *
		 * @return the tolls amount
		 */
		public double getTollsAmount() {
			return tollsAmount;
		}

		/**
		 * Gets the total amount.
		 *
		 * @return the total amount
		 */
		public double getTotalAmount() {
			return totalAmount;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Object#toString()
		 */
		@Override
		public String toString() {
			return "TaxiRecord [id=" + id + ", medallion=" + medallion + ", hashLicense=" + hashLicense
					+ ", pickupTime=" + pickupTime + ", dropOffTime=" + dropOffTime + ", duration=" + duration
					+ ", distance=" + distance + ", pLongitude=" + pLongitude + ", pLatitude=" + pLatitude
					+ ", dLongitude=" + dLongitude + ", dLatitude=" + dLatitude + ", paymentType=" + paymentType
					+ ", fareAmount=" + fareAmount + ", surchange=" + surchange + ", tax=" + tax + ", tipAmount="
					+ tipAmount + ", tollsAmount=" + tollsAmount + ", totalAmount=" + totalAmount + "]";
		}

		/**
		 * Sets the payment type.
		 *
		 * @param type
		 *            the new payment type
		 */
		public void setPaymentType(String type) {
			switch (type) {
			case "CSH":
				this.paymentType = PaymentType.CSH;
				break;
			case "CRD":
				this.paymentType = PaymentType.CRD;
				break;
			default:
				this.paymentType = PaymentType.UNK;
				break;
			}
		}
	}
}